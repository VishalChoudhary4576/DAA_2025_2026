public class MaxHeap {
    private static final int MAX = 100;
    private int[] heap = new int[MAX];
    private int heapSize = 0;

    public void insert(int value) {
        if (heapSize == MAX) {
            System.out.println("Heap Overflow");
            return;
        }

        int i = heapSize;
        heap[i] = value;
        heapSize++;

        while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }

    private void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heap[left] > heap[largest])
            largest = left;

        if (right < heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            heapify(largest);
        }
    }

    public int deleteRoot() {
        if (heapSize <= 0) {
            System.out.println("Heap Underflow");
            return -1;
        }

        int root = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;

        heapify(0);

        return root;
    }

    public void printHeap() {
        for (int i = 0; i < heapSize; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MaxHeap h = new MaxHeap();

        h.insert(10);
        h.insert(30);
        h.insert(20);
        h.insert(5);
        h.insert(40);

        System.out.println("Heap after insertion:");
        h.printHeap();

        System.out.println("Deleted root: " + h.deleteRoot());

        System.out.println("Heap after deletion:");
        h.printHeap();
    }
}