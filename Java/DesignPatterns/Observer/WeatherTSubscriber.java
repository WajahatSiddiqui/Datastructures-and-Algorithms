
public class WeatherTSubscriber implements WeatherObserver {

	@Override
	public void updateTemperature(float temp) {
		System.out.println("WeatherTSubscriber : new temperature = " + temp);
		
	}

	@Override
	public void updatePressure(float pressure) {
		// TODO Auto-generated method stub
		
	}

}
