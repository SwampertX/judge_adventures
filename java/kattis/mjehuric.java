import java.util.*;

class mjehuric{
    public static void main(String[] args){
        int[] arr = new int[5];
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<5; i++){
            arr[i] = sc.nextInt();
        }
        while(!isSorted(arr)){
            arr = bubbleSort(arr);
        }
    }

    private static boolean isSorted(int[] arr){
        for(int i=1; i<5; i++){
            if(arr[i] < arr[i-1]) return false;
        } return true;
    }

    private static int[] bubbleSort(int[] arr){
        for(int i=0; i<4; i++){
            if(arr[i] > arr[i+1]){
                arr[i+1] += arr[i];
                arr[i] = arr[i+1] - arr[i];
                arr[i+1] -= arr[i];
                printArr(arr);
            }
        }
       return arr;
    }

    private static void printArr(int[] arr){
        for(int i=0; i<5; i++){
            if(i!=0) System.out.printf(" ");
            System.out.printf("%d", arr[i]);
        }
        System.out.println();
    }
}
