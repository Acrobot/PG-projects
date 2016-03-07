package com.acrobot.lab4;

/**
 * @author Andrzej Pomirski
 */
public class InvalidShapeException extends Exception {
    public InvalidShapeException() {
        this("Invalid figure!");
    }

    public InvalidShapeException(String errorMessage) {
        super(errorMessage);
    }
}
