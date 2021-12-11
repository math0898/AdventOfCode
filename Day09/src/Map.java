import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 * The map class contains a 2d array of a region where each cell value is the height at a certain point. Lower values
 * means lower elevation.
 *
 * @author Sugaku
 */
public class Map {

    /**
     * An inner class used for storing x, y, and the value of a position in the board. For external use.
     *
     * @author Sugaku
     */
    public record Cell (int y, int x, int value) {}

    /**
     * These are the actual values given in the map.
     */
    private final int[][] board;

    /**
     * The height of the board.
     */
    private final int height;

    /**
     * The width of the board.
     */
    private final int width;

    /**
     * Creates a new map using the given ArrayList mapping.
     *
     * @param input This should be an ArrayList of ArrayLists each containing integers. It's the easiest way to get the
     *              input.
     */
    public Map (ArrayList<ArrayList<Integer>> input) {
        height = input.size();
        width = input.get(0).size();
        board = new int[height][width];
        for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) board[i][j] = input.get(i).get(j);
    }

    /**
     * Returns the width of the map.
     *
     * @return The width of the map.
     */
    public int getWidth () {
        return width;
    }

    /**
     * Returns the height of the map.
     *
     * @return The height of the map.
     */
    public int getHeight () {
        return height;
    }

    /**
     * Returns the value of the cell at the given coordinates.
     *
     * @param y The y coordinate of the cell.
     * @param x The x coordinate of the cell.
     * @return The value at the given cell. If out of bounds no error will be thrown and instead just -1.
     */
    public int getValue (int y, int x) {
        if (y < 0 || x < 0 || y >= height || x >= width) return -1;
        return board[y][x];
    }

    /**
     * Returns a Cell record that lives at the given coordinates.
     *
     * @param y The y coordinate of the cell.
     * @param x The x coordinate of the cell.
     * @return A Cell record which represents that cell.
     */
    public Cell getCell (int y, int x) {
        if (y < 0 || x < 0 || y >= height || x >= width) return null;
        return new Cell(y, x, board[y][x]);
    }

    /**
     * Prints the map to the console with a space between every cell.
     */
    public void print () {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) System.out.print(board[i][j] + " ");
            System.out.print("\n");
        }
    }

    /**
     * Returns a collection of cells which are surrounding the given cell. Cells are considered neighbors if they're
     * adjacent, not including corners.
     *
     * @param cell The cell the neighbors of should be returned.
     */
    public Collection<Cell> getNeighbors (Cell cell) {
        return getNeighbors(cell.y(), cell.x());
    }

    /**
     * Returns a collection of cells which are surrounding the given coordinates. Cells are considered neighbors if
     * they're adjacent, not including corners.
     *
     * @param y The y coordinate of the cell.
     * @param x The x coordinate of the cell.
     */
    public Collection<Cell> getNeighbors (int y, int x) {
        if (y < 0 || x < 0 || y >= height || x >= width) return Collections.emptyList();
        Collection<Cell> r = new ArrayList<>();
        if (y + 1 < height) r.add(new Cell(y + 1, x, board[y + 1][x]));
        if (y - 1 >= 0) r.add(new Cell(y - 1, x, board[y - 1][x]));
        if (x + 1 < width) r.add(new Cell(y, x + 1, board[y][x + 1]));
        if (x - 1 >= 0) r.add(new Cell(y, x - 1, board[y][x - 1]));
        return r;
    }

    /**
     * Marks the cell at the given coordinates. Cells are marked by adding 10 to their value.
     *
     * @param y The y coordinate of the cell to mark.
     * @param x The x coordinate of the cell to mark.
     */
    public void markCell (int y, int x) {
        if (y < 0 || x < 0 || y >= height || x >= width) return;
        if (board[y][x] < 10) board[y][x] += 10;
    }

    /**
     * Un-marks all cells in the board.
     */
    public void unMark () {
        for (int i = 0; i < height; i++) for (int j = 0; j < width; j++) if (board[i][j] >= 10) board[i][j] -= 10;
    }

    /**
     * Syncs the given cell to the current state of the board. Since Cell is a record the value cannot be modified and
     * so an updated version is returned instead.
     *
     * @param cell The cell to sync with the board state.
     * @return The cell updated to the board state.
     */
    public Cell syncCell (Cell cell) {
        return new Cell(cell.y(), cell.x(), board[cell.y()][cell.x()]);
    }
}
