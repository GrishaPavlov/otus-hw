#include "Ball.hpp"
#include <cmath>

Ball::Ball() {
    position = Point(0, 0);
    radius = 1;
    mass = 3.14 * std::pow(radius, 3) * 4. / 3;
    velocity = Velocity(0, 0);
    color = Color(1, 0, 0);
    collidable = false;
}


Ball::Ball(Point pos, double radius, double mass, Color color, bool collidable) {
    position = pos;
    this->radius = radius;
    this->mass = mass;
    this->color = color;
    this->collidable = collidable;
}


/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    // TODO: место для доработки
    this->velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() {
    // TODO: место для доработки
    return {velocity};
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки
    painter.draw(position, radius, color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    // TODO: место для доработки
    this->position = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() {
    // TODO: место для доработки
    return {position};
}

void Ball::setRadius(double radius) {
    this->radius = radius;
}

void Ball::setMass(double mass) {
    this->mass = mass;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    // TODO: место для доработки
    return {radius};
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const  {
    // TODO: место для доработки
    return {mass};
}

Color Ball::getColor() const  {
    return {color};
}

void Ball::setColor(const Color &color) {
    this->color = color;
}


void Ball::setCollidable(bool collidable) {
    this->collidable = collidable;
}

bool Ball::getCollidable() const {
    return collidable;
}
