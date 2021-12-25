import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static final int size = 1400;

    public static void main (String[] args) {
        int xSize = size;
        int ySize=  size;
        File f = new File("Day13/input.txt");
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
        ArrayList<Integer> folds = new ArrayList<>();
        while (file.hasNextLine()) {
            line = file.nextLine().replace("fold along ", "");
            if (line.contains("y=")) folds.add(Integer.parseInt(line.replace("y=", "")));
            else folds.add(-1 * Integer.parseInt(line.replace("x=", "")));
        }

        for (Integer hor : folds) {
            if (hor > 0) {
                char[][] temp = new char[hor][xSize];
                int mark = hor;
                for (int i = 0; i < hor; i++) for (int j = 0; j < xSize; j++) temp[i][j] = board[i][j];
                for (int i = hor + 1; i < ySize; i++) {
                    mark--;
                    for (int j = 0; j < xSize; j++) if (board[i][j] == '#') temp[mark][j] = '#';
                }
                ySize = hor;
                board = temp;
            } else {
                hor *= -1;
                char[][] temp = new char[ySize][hor];
                int mark = hor;
                for (int i = 0; i < ySize; i++) for (int j = 0; j < hor; j++) temp[i][j] = board[i][j];
                for (int i = 0; i < ySize; i++) {
                    mark = hor;
                    for (int j = hor + 1; j < xSize; j++) {
                        mark--;
                        if (board[i][j] == '#') temp[i][mark] = '#';
                    }
                }
                xSize = hor;
                board = temp;
            }
        }

        int hashes = 0;
        for (int i = 0; i < ySize; i++) {
            for (int j = 0; j < xSize; j++) {
                if (board[i][j] == '#') hashes++;
                System.out.print(board[i][j]);
            }
            System.out.print("\n");
        }
        System.out.println("Which has " + hashes + " hashes.");
    }
}
