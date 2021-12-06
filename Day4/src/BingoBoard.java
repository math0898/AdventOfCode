import java.util.Scanner;

/**
 * This class describes a bingo board. Each bingo board has a 5x5 grid and is won whenever someone has gotten a vertical
 * or horizontal line.
 *
 * @author Sugaku
 */
public class BingoBoard {

    /**
     * The actual board of numbers.
     */
    int[][] board = new int[5][5];

    /**
     * Creates a new bingo board using the given string array input.
     *
     * @param init The initial state of the bingo board in a string form.
     */
    BingoBoard (String[] init) {
        for (int i = 0; i < 5; i++) {
            Scanner line = new Scanner(init[i]);
            for (int j = 0; j < 5; j++) board[i][j] = line.nextInt();
        }
    }

    /**
     * Marks all the cells of the board with the given integer.
     *
     * @param m The number that if a cell has should be marked.
     */
    void mark (int m) {
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (board[i][j] == m) board[i][j] = -1;
    }

    /**
     * Checks if the board has been solved. Returns true if so.
     *
     * @return True if and only if the board contains a horizontal or vertical row of marked cells.
     */
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

    /**
     * Sums the unmarked values of the board and returns it.
     *
     * @return The value of unmarked cells in the BingoBoard.
     */
    int score () {
        int count = 0;
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (board[i][j] != -1) count += board[i][j];
        return count;
    }
}
