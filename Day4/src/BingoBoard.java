import java.util.Scanner;

public class BingoBoard {

    int[][] board = new int[5][5];

    BingoBoard (String[] init) {
        for (int i = 0; i < 5; i++) {
            Scanner line = new Scanner(init[i]);
            for (int j = 0; j < 5; j++) board[i][j] = line.nextInt();
        }
    }

    void mark (int m) {
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (board[i][j] == m) board[i][j] = -1;
    }

    boolean check () {
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
            if (board[j][i] != -1) break;
            else if (board[j][i] == -1 && j == 4) return true;
        }
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
            if (board[i][j] != -1) break;
            else if (board[i][j] == -1 && j == 4) return true;
        }
        return false;
    }

    int score () {
        int count = 0;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (board[i][j] != -1) count += board[i][j];
        return count;
    }
}
