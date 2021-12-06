import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        Scanner s;
        try {
            s = new Scanner(new File("Day1/input.txt")); 
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
            return;
        }
        ArrayList<Integer> data = new ArrayList<>();
        while (s.hasNextLine()) data.add(Integer.parseInt(s.nextLine()));
        int count = 0;
        for (int i = 1; i < data.size(); i++) if (data.get(i) > data.get(i -1)) count++;
        System.out.println("The depth increased: " + count + " times.");
        count = 0;
        for (int i = 2; i < data.size() - 1; i++) { // This is the center of the second window in the comparison.
            if (data.get(i + 1) > data.get(i - 2)) count++;
        }
        System.out.println("The 3 count window depth increased: " + count + " times.");
    }
}
