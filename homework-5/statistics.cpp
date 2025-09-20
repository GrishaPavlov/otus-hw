#include <algorithm>
#include <complex>
#include <iostream>
#include <limits>
#include <vector>

class IStatistics {
public:
    virtual ~IStatistics() {
    }

    virtual void update(double next) = 0;

    virtual double eval() const = 0;

    virtual const char *name() const = 0;
};

class Min : public IStatistics {
public:
    Min() : m_min{std::numeric_limits<double>::max()} {
    }

    void update(double next) override {
        if (next < m_min) {
            m_min = next;
        }
    }

    double eval() const override {
        return m_min;
    }

    const char *name() const override {
        return "min";
    }

private:
    double m_min;
};

class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::min()} {
    }

    void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char *name() const override {
        return "max";
    }

private:
    double m_max;
};

class Mean : public IStatistics {
public:
    Mean() : sum(0.) {
    }

    void update(double next) override {
        sum += next;
        values.push_back(next);
    }

    double eval() const override {
        if (values.size() == 0)
            return 0;
        return sum / values.size();
    }

    const char *name() const override {
        return "mean";
    }

private:
    std::vector<double> values;
    double sum;
};

class StdDev : public IStatistics {
public:
    StdDev() {
        sum = 0.0;
        mean_ = new Mean();
    }

    void update(double next) override {
        mean_->update(next);
        values.push_back(next);
    }

    double eval() const override {
        double sm = 0.0;
        for (int i = 0; i < values.size(); i++) {
            sm += std::pow(values[i] - mean_->eval(), 2);
        }
        return std::sqrt(sm / values.size());
    }

    const char *name() const override {
        return "standard deviation";
    }

    ~StdDev() {
        delete mean_;
    }

private:
    Mean *mean_;
    std::vector<double> values;
    double sum;
};

class Percentile : public IStatistics {
public:
    explicit Percentile(double p) : percent(p) {
    }

    void update(double next) override {
        values.push_back(next);
    }

    double eval() const override {
        std::sort(values.begin(), values.end());
        int rank = static_cast<int>(percent * values.size());
        return values[rank];
    }

    const char *name() const override {
        return "percentile";
    };

private:
    double percent;
    mutable std::vector<double> values;
};

class pct90 : public IStatistics {
public:
    pct90() {
        percent = new Percentile(0.9);
    }

    void update(double next) override {
        percent->update(next);
    }

    double eval() const override {
        return percent->eval();
    }

    const char *name() const override {
        return "90th percentile";
    }

private:
    Percentile *percent;
};

class pct95 : public IStatistics {
public:
    pct95() {
        percent = new Percentile(0.95);
    }

    void update(double next) override {
        percent->update(next);
    }

    double eval() const override {
        return percent->eval();
    }

    const char *name() const override {
        return "95th percentile";
    }

private:
    Percentile *percent;
};

int main() {
    const size_t statistics_count = 6;
    IStatistics *statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new StdDev{};
    statistics[4] = new pct90{};
    statistics[5] = new pct95{};

    double val = 0;
    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}
