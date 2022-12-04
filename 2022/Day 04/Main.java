import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    private static final String TO_READ = "2022/Day 04/input.txt";
    public static void main (String[] args) {
        Scanner s;
        try {
            s = new Scanner(new File(TO_READ));
        } catch(FileNotFoundException e) {
            System.out.println("Failed to read file.");
            return;
        }

        int subsets = 0;
        int overlaps = 0;

        while (s.hasNextLine()) {
            Scanner f = new Scanner(s.nextLine());
            f.useDelimiter("-");
            int a = f.nextInt();
            f.useDelimiter(",");
            int b = f.nextInt() * -1;
            Interval i1 = new Interval(a, b);
            f.useDelimiter("-");
            a = Integer.parseInt(f.next().replace(",", ""));
            b = f.nextInt();
            Interval i2 = new Interval(a, b);
            if (i1.subset(i2) || i2.subset(i1)) subsets++;
            if (i1.nonemptyIntersection(i2) || i2.nonemptyIntersection(i1)) overlaps++;
        }

        System.out.println("There are " + subsets 
        + " intervals which are a subset of another.");
        System.out.println("There are " + overlaps 
        + " intervals which overlap with one another.");
    }
}
