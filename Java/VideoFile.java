public class VideoFile {
	private String title;
	private String genre;
	private String nation;
	private Date publishingDate;
	
	//CONSTRUCTORS:
	VideoFile(String t, String g, String n, int d, int m, int y) {
		this.title = t;
		this.genre = g;
		this.nation = n;
		this.publishingDate = new Date(d, m, y);
	}
	
	
	
	public static String getTitle() {
		return title;
	}
}
