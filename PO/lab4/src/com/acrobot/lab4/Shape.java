package com.acrobot.lab4;

/**
 * @author Andrzej Pomirski
 */
public abstract class Shape {

    /**
     * Returns the area (inner size) of the shape
     * @return The area of the shape
     */
    public abstract double getArea();

    /**
     * Retirms the perimeter (size of the sides) of the figure
     * @return The perimeter of the figure
     */
    public abstract double getPerimeter();

    @Override
    public String toString() {
        return this.getClass().getSimpleName() + ", area: " + getArea() + ", perimeter " + getPerimeter();
    }
}
