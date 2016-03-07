package com.acrobot.lab4;

/**
 * @author Andrzej Pomirski
 */
public class ShapeFactory {
    public static Shape getShape(String name, double a, double b, double c) throws InvalidShapeException {
        switch(name) {
            case "triangle":
                return new Triangle(a, b, c);
            case "rectangle":
                return new Rectangle(a, b);
        }

        throw new InvalidShapeException("No shape found for the given name (" + name + ") " +
                "// Andrzej Pomirski");
    }
}
