import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main (String[] args) {
        SimFile root = new SimFile("", 0, null);
        SimFile currentDir = root;
        File file = new File("./2022/Day 07/input.txt");
        Scanner s;
        try {
            s = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("File not found!");
            return;
        }
        boolean list = false;
        while (s.hasNextLine()) {
            String line = s.nextLine();
            if (line.startsWith("$ ")) {
                list = false;
                if (line.equals("$ ls")) list = true;
                else if (line.contains("..")) currentDir = currentDir.getParent();
                else if (line.contains("cd")) {
                    line = line.replace("$ cd ", "");
                    for (SimFile f : currentDir.getSubfiles()) {
                        if (line.equals(f.getName())) {
                            currentDir = f;
                            break;
                        }
                    }
                }
            } else if (list) {
                long size = 0;
                if (!line.contains("dir")) size = Long.parseLong(line.split(" ")[0]);
                currentDir.addSubFile(new SimFile(line.split(" ")[1], size, currentDir));
            }
        }
        Stack<SimFile> toCheck = new Stack<>();
        List<SimFile> checked = new ArrayList<>();
        toCheck.push(root);
        BigInteger sum = BigInteger.valueOf(0);
        long toFree = 30000000 - (70000000 - root.getSize());
        long diff = toFree;
        SimFile currentBest = root;
        while (toCheck.size() > 0) {
            SimFile sf = toCheck.pop();
            for (SimFile f : sf.getSubfiles()) {
                if (!checked.contains(f)) {
                    toCheck.push(f);
                    checked.add(f);
                }
            }
            long size = sf.getSize();
            if (size < 100000 && sf.isDir()) {
                sum = sum.add(BigInteger.valueOf(size));
            }
            if (size > toFree && size - toFree < diff) {
                currentBest = sf;
                diff = size - toFree;
            }
        }
        System.out.println("Biggest Directories Size Sums to: " + sum);
        System.out.println("Best Canidate to Delete: " + currentBest.getSize());
        s.close();
    }
}
