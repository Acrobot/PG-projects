package com.acrobot.lab4;

public class Main {

    public static void main(String[] args) throws InvalidShapeException {
        Shape triangle = ShapeFactory.getShape("triangle", 3, 5, 6);
        System.out.println(triangle);

        Shape rectangle = ShapeFactory.getShape("rectangle", 1, 2, 3);
        System.out.println(rectangle);

        // This will throw an exception
        try {
            Shape nonexistant = ShapeFactory.getShape("diamond", 1, 2, 3);
        } catch (InvalidShapeException exception) {
            exception.printStackTrace();
        }
    }
}
