import java.io.File;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    /**
     * Prints the puzzle output in a usable format for both debugging and answering.
     *
     * @param output The puzzle output to be printing.
     * @param key The key for what each pair count is attached to.
     * @param leftover The leftover char at the end of the string.
     */
    private static void printSolution (ArrayList<BigInteger> output, ArrayList<String> key, Character leftover) {
        Map<Character, BigInteger> charCounts = new HashMap<>();
        for (int i = 0; i < key.size(); i++) {
            charCounts.putIfAbsent(key.get(i).charAt(0), BigInteger.ZERO);
            charCounts.replace(key.get(i).charAt(0), output.get(i).add(charCounts.get(key.get(i).charAt(0))));
            System.out.println(key.get(i) + " -> " + output.get(i));
        }
        charCounts.putIfAbsent(leftover, BigInteger.ZERO);
        charCounts.replace(leftover, charCounts.get(leftover).add(BigInteger.valueOf(1)));
        BigInteger min = BigInteger.valueOf(-1);
        BigInteger max = BigInteger.valueOf(-1);
        for (Character c : charCounts.keySet()) {
            if (min.equals(BigInteger.valueOf(-1)) || charCounts.get(c).compareTo(min) < 0) min = charCounts.get(c);
            if (max.equals(BigInteger.valueOf(-1)) || charCounts.get(c).compareTo(max) > 0) max = charCounts.get(c);
            System.out.println(c + ": " + charCounts.get(c));
        }
        System.out.println("Difference between max and min: " + max.subtract(min));
    }

    public static void main (String[] args) {
        File f = new File("Day14/input.txt");
        Scanner file;
        try {
            file = new Scanner(f);
        } catch (Exception e) {
            System.out.println("Failed to open file.");
            return;
        }
        ArrayList<String> key = new ArrayList<>();
        ArrayList<String> c = new ArrayList<>();
        ArrayList<BigInteger> pairs = new ArrayList<>();
        String current = file.nextLine();
        Character leftover = current.charAt(current.length() - 1);
        file.nextLine();
        while (file.hasNextLine()) {
            String line = file.nextLine();
            Scanner s = new Scanner(line);
            s.useDelimiter(" -> ");
            key.add(s.next());
            c.add(s.next());
            pairs.add(BigInteger.ZERO);
        }
        for (int i = 0; i < current.length() - 1; i++) {
            int index = key.indexOf(current.charAt(i) + "" + current.charAt(i + 1) + "");
            pairs.set(index, pairs.get(index).add(BigInteger.ONE));
        }
        int steps = 0;
        while (steps < 40) {
            if (steps == 10) {
                System.out.println(" ---- 10 Steps ----");
                printSolution(pairs, key, leftover);
            }
            ArrayList<BigInteger> temp = new ArrayList<>();
            for (int i = 0; i < key.size(); i++) temp.add(BigInteger.ZERO);
            for (int i = 0; i < key.size(); i++) {
                for (String s : new String[]{ key.get(i).charAt(0) + c.get(i), c.get(i) + key.get(i).charAt(1) }) {
                    int x = key.indexOf(s);
                    temp.set(x, pairs.get(i).add(temp.get(x)));
                }
            }
            pairs = temp;
            steps++;
        }
        System.out.println(" ---- 40 Steps ----");
        printSolution(pairs, key, leftover);
    }
}
