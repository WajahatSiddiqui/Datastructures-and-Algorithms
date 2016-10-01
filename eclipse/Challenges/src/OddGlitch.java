import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedHashMap;
import java.util.Map.Entry;
import java.util.Scanner;

/**
 * Given the test data of customer ids who has performed
 * the transactions, this class reads the test-data files
 * and process each file using processDataMethod()
 * 
 * Usage: Put this file under test-dir
 *        $ javac OddGlitch.java
 *        $ java OddGlitch ./
 * @author wajahat
 */
public class OddGlitch {
    // change this path for test-dir
    private static final String DEFAULT_TEST_DIR_PATH =
            "/home/habeeba/Wajahat/GitHub/Workspace/eclipse/Challenges/test-data";

    /**
     * Process the given testFile for given customer ids
     * Approach:
     * 1) Constructs HashMap for Key as customer Id and value 
     * as the occurance of the customer transaction (1 initially)
     * 2) If this customer id is again repeated, it hashmap
     * value is toggled.
     * 3) Finally once all the customer ids are served the one whose
     * transaction are successful will have the value 0 and onces whose
     * transaction are failed will have the value 1
     * 4) Print all the customers whose value is 1 if no such
     * customers exists print 0
     * Time Complexity: O(N) 
     * Space Complexity: O(N), HashMap
     * @param testFile
     * @throws FileNotFoundException
     */
    public static void processData(String testFile)
            throws FileNotFoundException {
        Scanner scanner = new Scanner(new FileInputStream(new File(testFile)));
        int N = scanner.nextInt();
        LinkedHashMap<Integer, Integer> transactionMap =
                new LinkedHashMap<Integer, Integer>(N);
        int customerId;
        System.out.print(" #Transactions: " + N + " Failed: ");
        while (N > 0) {
            customerId = scanner.nextInt();
            if (transactionMap.get(customerId) == null) {
                transactionMap.put(customerId, 1);
            } else {
                // toggle customer
                transactionMap.put(customerId, transactionMap.get(customerId) == 1 ? 0 : 1);
            }
            N--;
        }
        boolean hasFailedTrans = false;
        for (Entry<Integer, Integer> e : transactionMap.entrySet()) {
            if (e.getValue() == 1) {
                System.out.println(e.getKey());
                if (!hasFailedTrans)
                    hasFailedTrans = true;
            }
        }
        if (!hasFailedTrans)
            System.out.println(0);
        transactionMap.clear();
        transactionMap = null;
        scanner.close();
    }

    public static void main(String args[]) {
        String filePath;
        if (args.length > 1 && !args[1].isEmpty())
            filePath = args[1];
        else
            filePath = DEFAULT_TEST_DIR_PATH;
        File file = new File(filePath);
        if (file.exists() && file.isDirectory()) {
            String[] files = file.list();
            for (String fileName : files) {
                try {
                	System.out.print("TestFile: " + fileName); 
                    processData(filePath + "/" + fileName);
                } catch (FileNotFoundException e) {
                    System.out.println("Invalid fileName: " + fileName
                            + " Exception: " + e.getMessage());
                }
            }
        }
    }
}
