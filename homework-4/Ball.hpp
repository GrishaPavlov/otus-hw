#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Velocity velocity;
    Point position;
    double radius;
    double mass;
    Color color;
    Point center;
    bool collidable;
    Ball();
    Ball(Point pos, double radius, double mass, Color color, bool collidable);

    void setVelocity(const Velocity& velocity);
    Velocity getVelocity();

    void setCenter(const Point& center);
    Point getCenter();

    void setRadius(double radius);
    double getRadius() const;

    void setMass(double mass);
    double getMass() const;

    void setColor(const Color& color);
    Color getColor() const;

    void setCollidable(bool collidable);
    bool getCollidable() const;

    void draw(Painter& painter) const;
};
