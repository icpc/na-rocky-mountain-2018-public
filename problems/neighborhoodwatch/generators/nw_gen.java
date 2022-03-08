import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class nw_gen {

    private void generateFull(int fileNumber, int n) {
        String fileName = getFileName(fileNumber);
        try (PrintWriter pw = new PrintWriter(fileName)) {
            pw.printf("%d %d\n", n, n);
            for (int i = 1; i <= n; i++)
                pw.printf("%s%d", i > 1 ? " " : "", i);
            pw.println();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void generateCheckered(int fileNumber, int n) {
        String fileName = getFileName(fileNumber);
        try (PrintWriter pw = new PrintWriter(fileName)) {
            pw.printf("%d %d\n", n, (n + 1) / 2);
            int i = 1;
            while (i <= n) {
                pw.printf("%s%d", i > 1 ? " " : "", i);
                i += 2;
            }
            pw.println();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void generateRandom(int lo, int hi, int count, int fileNumber) {
        Random rnd = new Random();

        for (int off = 0; off < count; off++) {
            String fileName = getFileName(fileNumber + off);
            int n = rnd.nextInt(hi - lo + 1) + lo;
            int k = rnd.nextInt(n + 1);
            try (PrintWriter pw = new PrintWriter(fileName)) {
                pw.printf("%d %d\n", n, k);
                boolean fst = true;
                for (int i : getRandomList(n, k)) {
                    pw.printf("%s%d", fst ? "" : " ", i);
                    fst = false;
                }
                pw.println();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.exit(-1);
            }
        }
    }

    private String getFileName(int i) {
        return String.format("neighbourhoodwatch/neighbourhoodwatch-%02d.in", i);
    }

    private List<Integer> getRandomList(int n, int k) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) list.add(i);
        Collections.shuffle(list);
        list = list.subList(0, k);
        Collections.sort(list);
        return list;
    }

    public static void main(String[] args) {
        nw_gen gen = new nw_gen();
        gen.generateFull(20, 200000);

        gen.generateCheckered(30, 198737);

        gen.generateRandom(20, 50, 10, 40);
        gen.generateRandom(200, 1000, 5, 50);
        gen.generateRandom(10000, 20000, 3, 60);
        gen.generateRandom(180000, 200000, 2, 70);
    }
}
