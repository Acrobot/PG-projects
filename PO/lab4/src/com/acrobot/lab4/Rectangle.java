package com.acrobot.lab4;

/**
 * @author Andrzej Pomirski
 */
public class Rectangle extends Shape {
    private double a, b;

    public Rectangle(double a, double b) throws InvalidShapeException {
        this.a = a;
        this.b = b;

        if (a <= 0 || b <= 0) {
            throw new InvalidShapeException("Parameters should be greater than 0!");
        }
    }

    @Override
    public double getArea() {
        return a * b;
    }

    @Override
    public double getPerimeter() {
        return 2 * (a + b);
    }
}
