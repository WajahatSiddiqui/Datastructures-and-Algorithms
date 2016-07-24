import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;


public class MediaPlayer {
	private HashMap<String, File> mHashMap;
	private ArrayList<String> mIndices;
	private String mDirPath;
	
	public MediaPlayer(String path) {
		mDirPath = path;
		mHashMap = new HashMap<>();
		mIndices = new ArrayList<>();
	}
	
	public void loadPlayList() {
		File file = new File(mDirPath);
		if (file.isDirectory()) {
			File [] files = file.listFiles();
			for (File f : files) {
				System.out.println("Adding file: "+f.getName());
				mHashMap.put(f.getName(), f);
				mIndices.add(f.getName());
			}
		} else {
			System.out.println("Invalid " + mDirPath + " specified :(");
		}
	}
	
	Runnable runnable = new Runnable() {
		@Override
		public void run() {
			int size = mHashMap.size();
			Random random = new Random();
			int index;
			for (int i = 0; i < size; i++) {
				index = random.nextInt(size);
				System.out.println("Playing file: " + mHashMap.get(mIndices.get(index)));
	            try {
	                Thread.sleep(1000);
	            } catch(InterruptedException e) {
	            }
			}
		}
	};
	public void playRandom() {
		new Thread(runnable).run();
	}
	
	public static void main(String args[]) {
		String path = "/home/habeeba/Pictures";
		MediaPlayer mediaPlayer = new MediaPlayer(path);
		mediaPlayer.loadPlayList();
		mediaPlayer.playRandom();
	}
}
