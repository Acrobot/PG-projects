package com.acrobot.lab4;

import org.omg.CORBA.DynAnyPackage.Invalid;

/**
 * @author Andrzej Pomirski
 */
public class Triangle extends Shape {
    private double a, b, c;

    public Triangle(double a, double b, double c) throws InvalidShapeException {
        this.a = a;
        this.b = b;
        this.c = c;

        if (a <= 0 || b <= 0 || c <= 0) {
            throw new InvalidShapeException("Parameters should be greater than 0!");
        }
    }

    @Override
    public double getArea() {
        double semiPerimeter = (a + b + c) / 2;

        // Heron's formula
        return Math.sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    }

    @Override
    public double getPerimeter() {
        return a + b + c;
    }
}
