package Problem;

import java.util.Arrays;

public class PancakeSort {

    // Function to reverse array from index 0 to i
    static void flip(int arr[], int i) {
        int start = 0;
        while (start < i) {
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

    // Function to return index of maximum element in arr[0..n-1]
    static int findMax(int arr[], int n) {
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    // Function to perform pancake sorting
    static void pancakeSort(int arr[]) {
        int n = arr.length;

        // Start from the complete array and one by one reduce current size by one
        for (int currSize = n; currSize > 1; --currSize) {
            int maxIndex = findMax(arr, currSize); // find mex index

            // Move the maximum element to the end of the current array if it is not already at the end
            if (maxIndex != currSize - 1) {
                // To move at the end, first move maximum number to beginning
                flip(arr, maxIndex);
                // Now move the maximum number to end by reversing current array
                flip(arr, currSize - 1);
            }
        }
    }

    // Utility function to print array
    static void printArray(int arr[]) {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String args[]) {
        int arr[] = {2,1,3,6,4,8,7};
        System.out.print("Original Array: ");
        printArray(arr);
        pancakeSort(arr);
        System.out.print("Sorted Array: ");
        printArray(arr);
    }
}

