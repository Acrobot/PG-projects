package com.acrobot.lab3;

/**
 * @author Andrzej Pomirski
 */
public class Ball {
    private final int number;
    private boolean weighted;

    public Ball(int number, boolean weighted) {
        this.number = number;
        this.weighted = weighted;
    }

    public Ball(int number) {
        this(number, false);
    }

    public int getNumber() {
        return number;
    }

    public boolean isWeighted() {
        return weighted;
    }

    public void setWeighted(boolean weighted) {
        this.weighted = weighted;
    }
}
