import java.util.PriorityQueue;
import java.util.Scanner;

class Room {
	int st;
	 int en;

	public Room(int start, int end) {
		this.st = start;
		this.en = end;
	}
}

class RoomComparator implements java.util.Comparator<Room> {
	public RoomComparator() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public int compare(Room o1, Room o2) {
		if(o1.en == o2.en) {
			return o1.st - o2.st;
		}
		return o1.en - o2.en;
	}
}
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PriorityQueue<Room> pq = new PriorityQueue<Room>(1, new RoomComparator());
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			int s, e;
			s = sc.nextInt();
			e = sc.nextInt();
			pq.add(new Room(s, e));
		}
		
		int tot = 0;
		int curEnd = 0;
		while(!pq.isEmpty()) {
			Room room = pq.poll();
			if(curEnd <= room.st) {
				tot++;
				curEnd = room.en;
			}
		}
		System.out.println(tot);
		sc.close();
	}

}
