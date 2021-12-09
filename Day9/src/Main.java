import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main (String[] args) {
        ArrayList<ArrayList<Integer>> map = new ArrayList<>();
        Scanner s;
        try {
            s = new Scanner(new File("Day9/example.txt"));
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
            for (StackTraceElement e : exception.getStackTrace()) System.out.println(e.toString());
            return;
        }
        while (s.hasNextLine()) {
            String line = s.nextLine();
            ArrayList<Integer> intLine = new ArrayList<>();
            for (char c : line.toCharArray()) intLine.add(c - '0');
            map.add(intLine);
        }
        int riskCount = 0;
        int exit;
        ArrayList<Integer> basinSizes = new ArrayList<>();
        int basinSize;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map.get(i).size(); j++) {
                Integer current = map.get(i).get(j);
                exit = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        try {
                            if (map.get(i + di).get(j + dj) < current) exit = 1;
                        } catch (Exception ignored) { /* "I did nothing!" - King Bumi */ }
                        if (exit == 1) break;
                    }
                    if (exit == 1) break;
                }
                if (exit == 0) {
                    basinSize = 1;
                    Stack<Integer> toCheck = new Stack<>();
                    toCheck.add(i);
                    toCheck.add(j);
                    riskCount += 1 + map.get(i).get(j);
                    while (!toCheck.empty()) {
                        int y = toCheck.pop();
                        int x = toCheck.pop();
                        if (y >= map.size() || y < 0) continue;
                        if (x >= map.get(y).size() || x < 0 ) continue;
                        if (map.get(y).get(x) == 9) continue;
                        for (int dx = -1; dx <= 1; dx++) for (int dy = -1; dy <= 1; dy++) {
                            if (Math.abs(dx) == Math.abs(dy)) continue;
                            try {
                                int check = map.get(y + dy).get(x + dx);
                                if (check != 9 && check > map.get(y).get(x)) {
                                    toCheck.add(y + dy);
                                    toCheck.add(x + dx);
                                }
                            } catch (Exception ignored) { /* "I did nothing!" - King Bumi */ }
                        }
                        map.get(y).set(x, 9);
                        basinSize++;
                    }
                    System.out.print("\n");
                    basinSizes.add(basinSize);
                }
            }
        }
        System.out.println("The risk value of this map is: " + riskCount);
        for (Integer i : basinSizes) System.out.println(i);
    }
}
