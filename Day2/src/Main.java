import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /**
     * The relative path, starting from project source, to the input file.
     */
    private static final String filename = "Day2/input.txt";

    /**
     *
     *
     * @param data The data to use whilst counting.
     */
    public static void part1 (ArrayList<Integer> data) {

    }

    /**
     *
     *
     * @param data The data to use whilst counting.
     */
    public static void part2 (ArrayList<Integer> data) {

    }

    /**
     * The main execution point of the program.
     *
     * @param args The arguments given to the executable.
     */
    public static void main (String[] args) {
        try {
            File f = new File(filename);
            Scanner s = new Scanner(f);
            int horizontal = 0;
            int depth = 0;
            while (s.hasNextLine()) {
                String input = s.nextLine();
                if (input.contains("forward")) {
                    horizontal += Integer.parseInt(input.replace("forward ", ""));
                } else if (input.contains("up")) depth -= Integer.parseInt(input.replace("up ", ""));
                else if (input.contains("down")) depth += Integer.parseInt(input.replace("down ", ""));
            }
            System.out.println(horizontal * depth);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }
}
