import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

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
     * @param args The arguments given to the executable.
     */
    public static void main (String args[]) {

        String filepath = "Day1/input.txt";
        int count = 0;
        try {
            File f = new File(filepath);
            System.out.println(f.getAbsoluteFile());
            Scanner s = new Scanner(f);
//            ---- Part 1 ----
//            int previous = 0;
//            int current = Integer.parseInt(s.nextLine());
//            while (s.hasNextLine()) {
//                previous = current;
//                current = Integer.parseInt(s.nextLine());
//                if (current > previous) count++;
//            }
            ArrayList<Integer> data = new ArrayList<>();
            while (s.hasNextLine()) data.add(Integer.parseInt(s.nextLine()));
            for (int i = 2; i < data.size() - 1; i++) { // This is the center of the second window in the comparison.
//                int sum1 = data.get(i - 2) + data.get(i - 1) + data.get(i); // Naive solution
//                int sum2 = data.get(i - 1) + data.get(i) + data.get(i + 1);
                if (data.get(i + 1) > data.get(i - 2)) count++;
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
        System.out.println("The depth increased: " + count + " times.");
    }
}
