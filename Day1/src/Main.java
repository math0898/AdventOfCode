import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /**
     * The relative path, starting from project source, to the input file.
     */
    private static final String filename = "Day1/input.txt";

    /**
     * As the submarine drops below the surface of the ocean, it automatically performs a sonar sweep of the nearby sea
     * floor. On a small screen, the sonar sweep report (your puzzle input) appears: each line is a measurement of the
     * sea floor depth as the sweep looks further and further away from the submarine.
     *
     * The first order of business is to figure out how quickly the depth increases, just so you know what you're
     * dealing with - you never know if the keys will get carried into deeper water by an ocean current or a fish or
     * something.
     *
     * To do this, count the number of times a depth measurement increases from the previous measurement. (There is no
     * measurement before the first measurement.)
     *
     * @param data The data to use whilst counting.
     */
    public static void part1 (ArrayList<Integer> data) {
        int count = 0;
        for (int i = 1; i < data.size(); i++) if (data.get(i) > data.get(i -1)) count++;
        System.out.println("The depth increased: " + count + " times.");
    }

    /**
     * Instead, consider sums of a three-measurement sliding window. Start by comparing the first and second
     * three-measurement windows. The measurements in the first window are marked A (199, 200, 208); their sum is
     * 199 + 200 + 208 = 607. The second window is marked B (200, 208, 210); its sum is 618. The sum of measurements in
     * the second window is larger than the sum of the first, so this first comparison increased.
     *
     * Your goal now is to count the number of times the sum of measurements in this sliding window increases from the
     * previous sum. So, compare A with B, then compare B with C, then C with D, and so on. Stop when there aren't
     * enough measurements left to create a new three-measurement sum.
     *
     * @param data The data to use whilst counting.
     */
    public static void part2 (ArrayList<Integer> data) {
        int count = 0;
        for (int i = 2; i < data.size() - 1; i++) { // This is the center of the second window in the comparison.
            if (data.get(i + 1) > data.get(i - 2)) count++;
        }
        System.out.println("The 3 count window depth increased: " + count + " times.");
    }

    /**
     * Main execution point for the program.
     *
     * @param args The arguments that would be given to this program through command line.
     */
    public static void main (String[] args) {
        try {
            Scanner s = new Scanner(new File(filename));
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
