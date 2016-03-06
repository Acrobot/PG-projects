package com.acrobot.lab3;

import java.util.*;

/**
 * @author Andrzej Pomirski
 */
public class DrawingMachine {
    private final List<Ball> balls;

    private final Random random = new Random();
    private final Timer timer = new Timer();
    private final TimerTask timerTask = new TimerTask() {
        @Override
        public void run() {
            int firstIndex = random.nextInt(balls.size() - 1);
            int secondIndex = random.nextInt(balls.size() - 1);

            Collections.swap(balls, firstIndex, secondIndex);

            for (int i = 1; i < balls.size(); ++i) {
                if (!balls.get(i).isWeighted()) {
                    continue;
                }

                Collections.swap(balls, i, i - 1);
            }
        }
    };

    public DrawingMachine(List<Ball> balls) {
        this.balls = balls;
    }

    /**
     * Starts the drawing mechanism
     */
    public void start() {
        timer.scheduleAtFixedRate(timerTask, 0, /* every */ 10 /* ms */);
    }

    /**
     * Stops the drawing and returns the first 6 balls
     * @return List of 6 lucky balls
     */
    public List<Ball> stop() {
        return balls.subList(0, 6);
    }
}
