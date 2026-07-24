package Arrays;

import java.util.Arrays;

/**
 * ArrayBasics.java
 * ----------------
 * A comprehensive guide to understanding and using Arrays in Java.
 * Designed as a teaching tool for students to master core array concepts.
 * 
 * Topics Covered:
 * 1. Declaration & Initialization
 * 2. Accessing & Modifying Elements
 * 3. Array Traversal (Different Loop Styles)
 * 4. Basic Operations (Search, Sum, Average, Min/Max)
 * 5. Shifting Elements (Insertion & Deletion simulation in fixed-size arrays)
 * 6. Multi-dimensional (2D) Arrays
 * 7. Java Arrays Utility Class
 */
public class ArrayBasics {

    public static void main(String[] args) {
        System.out.println("==================================================");
        System.out.println("          JAVA ARRAYS COMPREHENSIVE GUIDE         ");
        System.out.println("==================================================\n");

        demoDeclarationAndInitialization();
        demoAccessAndModify();
        demoTraversal();
        demoBasicOperations();
        demoInsertionAndDeletion();
        demoTwoDimensionalArrays();
        demoArraysUtilityClass();
    }

    /**
     * Topic 1: Declaration and Initialization
     */
    private static void demoDeclarationAndInitialization() {
        System.out.println("--- 1. Declaration & Initialization ---");

        // Syntax A: Declare and then allocate memory (default values: 0 for int)
        int[] arr1 = new int[5]; // size of 5 elements, initialized to [0, 0, 0, 0, 0]

        // Syntax B: Declare and initialize with values directly (Literal initialization)
        int[] arr2 = {10, 20, 30, 40, 50};

        // Syntax C: Using the 'new' keyword with values
        int[] arr3 = new int[]{1, 3, 5, 7, 9};

        System.out.println("arr1 (allocated with size 5) length: " + arr1.length);
        System.out.println("arr2 (literal initialization) length: " + arr2.length);
        System.out.println("arr3 (new keyword with literals) length: " + arr3.length);
        System.out.println();
    }

    /**
     * Topic 2: Accessing and Modifying Elements
     */
    private static void demoAccessAndModify() {
        System.out.println("--- 2. Accessing & Modifying Elements ---");
        int[] numbers = {100, 200, 300};

        // Accessing elements (0-indexed)
        System.out.println("Element at index 0: " + numbers[0]);
        System.out.println("Element at index 2: " + numbers[2]);

        // Modifying elements
        numbers[1] = 999;
        System.out.println("Modified element at index 1: " + numbers[1]);
        System.out.println();
    }

    /**
     * Topic 3: Array Traversal
     */
    private static void demoTraversal() {
        System.out.println("--- 3. Array Traversal Methods ---");
        String[] fruits = {"Apple", "Banana", "Cherry", "Mango"};

        // Method A: Standard for-loop (best if index is needed)
        System.out.print("Standard for-loop: ");
        for (int i = 0; i < fruits.length; i++) {
            System.out.print(fruits[i] + " (Index " + i + ") ");
        }
        System.out.println();

        // Method B: Enhanced for-loop / For-each (simpler, read-only)
        System.out.print("Enhanced for-each loop: ");
        for (String fruit : fruits) {
            System.out.print(fruit + " ");
        }
        System.out.println();

        // Method C: While loop
        System.out.print("While-loop traversal: ");
        int index = 0;
        while (index < fruits.length) {
            System.out.print(fruits[index] + " ");
            index++;
        }
        System.out.println("\n");
    }

    /**
     * Topic 4: Basic Operations
     */
    private static void demoBasicOperations() {
        System.out.println("--- 4. Basic Array Operations ---");
        int[] values = {12, 45, 2, 67, 34, 9, 23};

        // Find Sum and Average
        int sum = 0;
        for (int val : values) {
            sum += val;
        }
        double average = (double) sum / values.length;

        // Find Min & Max
        int min = values[0];
        int max = values[0];
        for (int i = 1; i < values.length; i++) {
            if (values[i] < min) {
                min = values[i];
            }
            if (values[i] > max) {
                max = values[i];
            }
        }

        // Linear Search
        int target = 67;
        int targetIndex = -1;
        for (int i = 0; i < values.length; i++) {
            if (values[i] == target) {
                targetIndex = i;
                break;
            }
        }

        System.out.println("Array: " + Arrays.toString(values));
        System.out.println("Sum: " + sum);
        System.out.printf("Average: %.2f\n", average);
        System.out.println("Minimum Element: " + min);
        System.out.println("Maximum Element: " + max);
        System.out.println("Search target " + target + " found at index: " + targetIndex);
        System.out.println();
    }

    /**
     * Topic 5: Shifting Elements (Insert & Delete in Fixed-Size Arrays)
     */
    private static void demoInsertionAndDeletion() {
        System.out.println("--- 5. Insertion & Deletion (Shifting Elements) ---");
        
        // Since arrays have a fixed size in memory, to insert or delete elements,
        // we must manually shift elements.
        
        // Let's create an array of capacity 8, containing 5 active elements
        int[] arr = new int[8];
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
        int size = 5; // Number of elements currently in the array
        
        System.out.println("Initial array: " + Arrays.toString(arr) + " (Size: " + size + ")");

        // 1. INSERTION: Insert element 99 at index 2
        int insertIndex = 2;
        int newElement = 99;

        // Shift elements from index 2 to right
        for (int i = size; i > insertIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insertIndex] = newElement;
        size++; // increment size

        System.out.println("After inserting " + newElement + " at index " + insertIndex + ": " 
                           + Arrays.toString(arr) + " (Size: " + size + ")");

        // 2. DELETION: Delete element at index 3 (which is 30)
        int deleteIndex = 3;

        // Shift elements from index 4 to left
        for (int i = deleteIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = 0; // Clear last element
        size--; // decrement size

        System.out.println("After deleting element at index " + deleteIndex + ": " 
                           + Arrays.toString(arr) + " (Size: " + size + ")");
        System.out.println();
    }

    /**
     * Topic 6: Multi-dimensional (2D) Arrays
     */
    private static void demoTwoDimensionalArrays() {
        System.out.println("--- 6. Multi-dimensional (2D) Arrays ---");

        // A 2D array is an array of arrays
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // Traversal using nested loops
        System.out.println("Matrix Traversal:");
        for (int row = 0; row < matrix.length; row++) {
            for (int col = 0; col < matrix[row].length; col++) {
                System.out.print(matrix[row][col] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Topic 7: java.util.Arrays Utility Class
     */
    private static void demoArraysUtilityClass() {
        System.out.println("--- 7. java.util.Arrays Utilities ---");
        int[] arr = {5, 2, 9, 1, 3};

        // 1. toString(): Easy printing
        System.out.println("Before sorting: " + Arrays.toString(arr));

        // 2. sort(): In-place sorting (Dual-Pivot Quicksort)
        Arrays.sort(arr);
        System.out.println("After sorting: " + Arrays.toString(arr));

        // 3. binarySearch(): Fast search on sorted array (returns index, or negative if not found)
        int searchIdx = Arrays.binarySearch(arr, 3);
        System.out.println("Binary search index of 3: " + searchIdx);

        // 4. copyOf(): Resize / copy array
        int[] largerArr = Arrays.copyOf(arr, 8);
        System.out.println("Copied/Resized array (size 8): " + Arrays.toString(largerArr));
        System.out.println();
    }
}
