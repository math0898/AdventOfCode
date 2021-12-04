import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static void mark (ArrayList<int[][]> boards, int i) {
        boards.forEach((b) -> {
            for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++) if (b[j][k] == i) b[j][k] = -1;
        });
    }

    static int check (ArrayList<int[][]> boards) {
        for (int i = 0; i < boards.size(); i++) {
            int[][] board = boards.get(i);
            boolean check = true;
            //Check horizontals
            for (int j = 0; j < 5; j++) {
                check = true;
                for (int k = 0; k < 5; k++) if (board[j][k] != -1) {
                    check = false;
                    break;
                }
                if (check) break;
            }
            if (check) return i;
            //Check Verticals
            for (int j = 0; j < 5; j++) {
                check = true;
                for (int k = 0; k < 5; k++) if (board[k][j] != -1) {
                    check = false;
                    break;
                }
                if (check) break;
            }
            if (check) return i;
        }
        return -1;
    }

    public static void main (String[] args) {
        Scanner s;
        try { s = new Scanner(new File("Day4/input.txt"));
        } catch (IOException e) { return; }
        String firstLine = s.nextLine();
        Scanner s2 = new Scanner(firstLine);
        s2.useDelimiter(",");
        ArrayList<Integer> moves = new ArrayList<>();
        while (s2.hasNext()) moves.add(s2.nextInt());
        ArrayList<int[][]> boards = new ArrayList<>();
        while (s.hasNextLine()) {
            int[][] current = new int[5][5];
            boards.add(current);
            s.nextLine(); // Empty line between boards
            for (int i = 0; i < 5; i++) {
                Scanner line = new Scanner(s.nextLine());
                for (int j = 0; j < 5; j++) current[i][j] = line.nextInt();
            }
        }
        int b = -1;
        for (int m : moves) {
            if (boards.size() == 0) break; //Part 2
            mark(boards, m);
            b = check(boards);
            if (b != -1) {
                int sum = 0;
                for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (boards.get(b)[i][j] != -1) sum += boards.get(b)[i][j];
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) System.out.print(boards.get(b)[i][j] + " ");
                    System.out.print("\n");
                }
                System.out.println("The Sum of Unmarked Numbers: " + sum);
                System.out.println("The Number Pulled: " + m);
                System.out.println("The Solution: " + m * sum);
                while (b != -1) { // Part 2
                    boards.remove(b);
                    b = check(boards);
                }
            }
        }

    }
}
