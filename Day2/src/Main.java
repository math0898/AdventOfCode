import java.io.File;
import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        Scanner s;
        try {
            s = new Scanner(new File("Day2/input.txt"));
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
            return;
        }
        int horizontal = 0;
        int depth1 = 0;
        int depth2 = 0;
        while (s.hasNextLine()) {
            String input = s.next();
            switch (input) {
                case "forward" -> {
                    int t = s.nextInt();
                    horizontal += t;
                    depth2 += t * depth1;
                }
                case "up" -> depth1 -= s.nextInt();
                case "down"-> depth1 += s.nextInt();
            }
        }
        System.out.println("Part 1 (Horizontal, Depth): (" + horizontal + ", " + depth1 + ") => " + horizontal * depth1);
        System.out.println("Part 2 (Horizontal, Depth): (" + horizontal + ", " + depth2 + ") => " + horizontal * depth2);
    }
}
