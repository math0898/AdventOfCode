import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        Scanner s;
        try { s = new Scanner(new File("Day4/input.txt"));
        } catch (IOException e) { return; }
        Scanner movesString = new Scanner(s.nextLine());
        movesString.useDelimiter(",");
        ArrayList<Integer> moves = new ArrayList<>();
        while (movesString.hasNext()) moves.add(movesString.nextInt());
        ArrayList<BingoBoard> boards = new ArrayList<>();
        while (s.hasNextLine()) {
            s.nextLine(); // Empty line between boards
            if (s.hasNextLine()) boards.add(new BingoBoard(new String[]{ s.nextLine(), s.nextLine(), s.nextLine(), s.nextLine(), s.nextLine() }));
        }
        for (int m : moves) {
            if (boards.size() == 0) break; //Part 2
            boards.forEach((b) -> b.mark(m));
            ArrayList<Integer> toRemove = new ArrayList<>();
            boards.forEach((b) -> {
                if (b.check()) {
                    toRemove.add(boards.indexOf(b));
                    System.out.println("The sum of unmarked numbers: " + b.score());
                    System.out.println("The number pulled: " + m);
                    System.out.println("The solution: " + m * b.score());
                }
            });
            for (int i = toRemove.size() - 1; i >= 0; i--) boards.remove((int) toRemove.get(i));
        }
    }
}
