public class WeatherPSubscriber implements WeatherObserver {

	@Override
	public void updateTemperature(float temp) {
				
	}

	@Override
	public void updatePressure(float pressure) {
		System.out.println("WeatherPSubscriber: new pressure = " + pressure);
	}
}
