import java.io.File;
import java.io.IOException;
import java.util.*;

public class Main {

    public static void main (String[] args) {
        ArrayList<ArrayList<Integer>> input = new ArrayList<>();
        Scanner s;
        try {
            s = new Scanner(new File("Day9/input.txt"));
        } catch (IOException exception) {
            System.out.println(exception.getMessage());
            for (StackTraceElement e : exception.getStackTrace()) System.out.println(e.toString());
            return;
        }
        while (s.hasNextLine()) {
            String line = s.nextLine();
            ArrayList<Integer> intLine = new ArrayList<>();
            for (char c : line.toCharArray()) intLine.add(c - '0');
            input.add(intLine);
        }
        Map map = new Map(input);
        map.print();
        ArrayList<Map.Cell> localMin = new ArrayList<>();
        for (int i = 0; i < map.getHeight(); i++) {
            for (int j = 0; j < map.getWidth(); j++) {
                int current = map.getValue(i, j);
                if (current == 9) continue;
                boolean min = true;
                for (Map.Cell c : map.getNeighbors(i, j)) {
                    if (c.value() < current) {
                        min = false;
                        break;
                    }
                }
                if (min) localMin.add(map.getCell(i, j));
            }
        }
        int riskValue = 0;
        for (Map.Cell c : localMin) riskValue += c.value() + 1;
        System.out.println("The risk count for this map is: " + riskValue);
        ArrayList<Integer> basinSizes = new ArrayList<>();
        for (Map.Cell min : localMin) {
            int size = 0;
            Stack<Map.Cell> toCheck = new Stack<>();
            toCheck.add(min);
            while (!toCheck.empty()) {
                Map.Cell current = toCheck.pop();
                current = map.syncCell(current);
                if (current.value() >= 10) continue;
                size++;
                Collection<Map.Cell> neighbors = map.getNeighbors(current);
                for (Map.Cell c : neighbors) if (c.value() > current.value() && c.value() < 9) toCheck.add(c);
                map.markCell(current.y(), current.x());
            }
            basinSizes.add(size);
            map.unMark();
        }
        basinSizes.sort(Integer::compareTo);
        System.out.println("The three largest basins are: " + basinSizes.get(basinSizes.size() - 3) + " * "
                + basinSizes.get(basinSizes.size() - 2) + " * " + basinSizes.get(basinSizes.size() - 1) + " = "
                + basinSizes.get(basinSizes.size() - 3) * basinSizes.get(basinSizes.size() - 2) * basinSizes.get(basinSizes.size() - 1));
    }
}
