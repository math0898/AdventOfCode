import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    /**
     *
     *
     * @param args The arguments given to the executable.
     */
    public static void main (String args[]) {
        String filepath = "Day2/input.txt";
        int count = 0;
        try {
            File f = new File(filepath);
            Scanner s = new Scanner(f);
            ArrayList<Integer> data = new ArrayList<>();
            while (s.hasNextLine()) data.add(Integer.parseInt(s.nextLine()));
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }
}
