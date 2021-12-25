import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static final int size = 15;

    public static void main (String[] args) {
        File f = new File("Day13/example.txt");
        Scanner file;
        try {
            file = new Scanner(f);
        } catch (Exception e) {
            System.out.println("Failed to open file.");
            return;
        }
        char[][] board = new char[size][size];
        for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) board[i][j] = '.';
        String line = file.nextLine();
        while (!line.equals("")) {
            Scanner s = new Scanner(line);
            s.useDelimiter(",");
            int x = s.nextInt();
            int y = s.nextInt();
            board[y][x] = '#';
            line = file.nextLine();
        }
        ArrayList<Integer> horizontalFolds = new ArrayList<>();
        ArrayList<Integer> verticalFolds = new ArrayList<>();
        while (file.hasNextLine()) {
            line = file.nextLine().replace("fold along ", "");
            if (line.contains("y=")) horizontalFolds.add(Integer.parseInt(line.replace("y=", "")));
            else verticalFolds.add(Integer.parseInt(line.replace("x=", "")));
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) System.out.print(board[i][j]);
            System.out.print("\n");
        }
        System.out.println("\nHorizontal folds: ");
        for (Integer i : horizontalFolds) System.out.println("> " + i);
        System.out.println("\nVertical folds: ");
        for (Integer i : verticalFolds) System.out.println("> " + i);
    }
}
