import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /**
     * The relative path, starting from project source, to the input file.
     */
    private static final String filename = "Day1/input.txt";

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
            ArrayList<Integer> data = new ArrayList<>();
            while (s.hasNextLine()) data.add(Integer.parseInt(s.nextLine()));
            part1(data);
            part2(data);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }
}
