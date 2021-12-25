import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        File f = new File("Day14/input.txt");
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
        int steps = 0;
        while (steps < 10) {
            String temp = "";
            for (int i = 0; i < current.length() - 1; i++) {
                temp += current.charAt(i);
                String insert = "";
                for (int j = 0; j < key.size(); j++)
                    if (current.charAt(i) == key.get(j).charAt(0))
                        if (current.charAt(i + 1) == key.get(j).charAt(1))
                            insert = c.get(j);
                temp += insert;
            }
            temp += current.charAt(current.length() - 1);
            current = temp;
            steps++;
        }
        int charMax = -1;
        int charMin = -1;
        for (String check : c) {
            int count = current.length() - current.replace(check, "").length();
            if (count > charMax || charMax == -1) charMax = count;
            if (count < charMin || charMin == -1) charMin = count;
        }
        System.out.println(charMax + " - " + charMin);
        System.out.println("Difference between least common and most: " + (charMax - charMin));
    }
}
