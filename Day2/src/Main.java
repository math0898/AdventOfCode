import java.io.File;
import java.util.Scanner;

public class Main {

    /**
     * The relative path, starting from project source, to the input file.
     */
    private static final String filename = "Day2/input.txt";

    /**
     * It seems like the submarine can take a series of commands like forward 1, down 2, or up 3:
     *
     * - `forward X` increases the horizontal position by X units.
     * - `down X` increases the depth by X units.
     * - `up X` decreases the depth by X units.
     *
     * The submarine seems to already have a planned course (your puzzle input).
     *
     * Calculate the horizontal position and depth you would have after following the planned course. What do you get if
     * you multiply your final horizontal position by your final depth?
     */
    public static void part1 () {
        try {
            File f = new File(filename);
            Scanner s = new Scanner(f);
            int horizontal = 0;
            int depth = 0;
            while (s.hasNextLine()) {
                String input = s.next();
                switch (input) {
                    case "forward" -> horizontal += s.nextInt();
                    case "up" -> depth -= s.nextInt();
                    case "down"-> depth += s.nextInt();
                }
            }
            System.out.println("Part 1 (Horizontal, Depth): (" + horizontal + ", " + depth + ") => " + horizontal * depth);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }

    /**
     * In addition to horizontal position and depth, you'll also need to track a third value, aim, which also starts at
     * 0. The commands also mean something entirely different than you first thought:
     *
     * - `down X` increases your aim by X units.
     * - `up X` decreases your aim by X units.
     * - `forward X` does two things:
     *      - It increases your horizontal position by X units.
     *      - It increases your depth by your aim multiplied by X.
     *
     * Using this new interpretation of the commands, calculate the horizontal position and depth you would have after
     * following the planned course. What do you get if you multiply your final horizontal position by your final depth?
     */
    public static void part2 () {
        try {
            File f = new File(filename);
            Scanner s = new Scanner(f);
            int horizontal = 0;
            int depth = 0;
            int aim = 0;
            while (s.hasNextLine()) {
                String input = s.next();
                switch (input) {
                    case "forward" -> {
                        int t = s.nextInt();
                        horizontal += t;
                        depth += t * aim;
                    }
                    case "up" -> aim -= s.nextInt();
                    case "down"-> aim += s.nextInt();
                }
            }
            System.out.println("Part 2 (Horizontal, Depth): (" + horizontal + ", " + depth + ") => " + horizontal * depth);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }

    /**
     * The main execution point of the program.
     *
     * @param args The arguments given to the executable.
     */
    public static void main (String[] args) {
        part1();
        part2();
    }
}
