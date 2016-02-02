
public class WeatherTest {
	public static void main(String args[]) {
		WeatherPublisher weatherPublisher = new WeatherPublisher(25.2f, 14.5f);
		WeatherTSubscriber weatherTSubscriber = new WeatherTSubscriber();
		WeatherPSubscriber weatherPSubscriber = new WeatherPSubscriber();
		weatherPublisher.addObserver(weatherTSubscriber);
		weatherPublisher.addObserver(weatherPSubscriber);
		
		weatherPublisher.setTemperature(27.7f);
		weatherPublisher.setPressure(13.2f);
		
		weatherPublisher.removeObserver(weatherTSubscriber);
		weatherPublisher.setTemperature(10.0f);
		
		weatherPublisher.setPressure(12.5f);
		
		weatherPublisher.clearObserver();
		weatherPublisher.setTemperature(22.0f);
		weatherPublisher.setPressure(19.5f);		

	}
}
