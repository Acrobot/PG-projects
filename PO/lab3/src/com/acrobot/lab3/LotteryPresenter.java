package com.acrobot.lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import static java.lang.System.out;

/**
 * @author Andrzej Pomirski
 */
public class LotteryPresenter {

    private static final int BALL_COUNT = 49;

    public static void main(String... args) throws InterruptedException {
        List<Ball> balls = new ArrayList<Ball>();

        for (int i = 1; i <= BALL_COUNT; ++i) {
            Ball ball = new Ball(i);
            balls.add(ball);
        }

        Random random = new Random();
        for (int i = 0; i < 6; ++i) {
            int ballIndex = random.nextInt(BALL_COUNT);
            balls.get(ballIndex).setWeighted(true); //Cheaters!
        }

        DrawingMachine drawingMachine = new DrawingMachine(balls);

        out.println("Hello and welcome to the next Lotto drawing");
        out.println("The drawing machine has started the shuffling...");

        drawingMachine.start();

        Thread.sleep(1000);

        List<Ball> drawnBalls = drawingMachine.stop();

        out.println("The numbers are: ");
        for (Ball ball : drawnBalls) {
            out.print(ball.getNumber() + ", ");
        }

        System.exit(0);
    }
}
