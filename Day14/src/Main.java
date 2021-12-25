import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        File f = new File("Day14/example.txt");
        Scanner file;
        try {
            file = new Scanner(f);
        } catch (Exception e) {
            System.out.println("Failed to open file.");
            return;
        }
        ArrayList<String> key = new ArrayList<>();
        ArrayList<String> c = new ArrayList<>();
        String current = file.nextLine();
        file.nextLine();
        while (file.hasNextLine()) {
            String line = file.nextLine();
            Scanner s = new Scanner(line);
            s.useDelimiter(" -> ");
            key.add(s.next());
            c.add(s.next());
        }
        System.out.println(current);
        for (int i = 0 ; i < key.size(); i++) System.out.println(key.get(i) + " -> " + c.get(i));
    }
}
