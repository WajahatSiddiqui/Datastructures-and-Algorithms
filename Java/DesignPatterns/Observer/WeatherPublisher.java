import java.util.ArrayList;

public class WeatherPublisher {
	float mTemperature;
	float mPressure;
	ArrayList<WeatherObserver> mObserverList = new ArrayList<>();
	
	public WeatherPublisher(float temp, float pressure) {
		mTemperature = temp;
		mPressure = pressure;
		System.out.println("WeatherPublisher: temperature = " + mTemperature
				+ " pressure = " + mPressure);
		
	}
	
	public void addObserver(WeatherObserver obs) {
		if (!mObserverList.contains(obs)) {
			System.out.println("addObserver WeatherObserver : " + obs.toString());
			mObserverList.add(obs);
		}
	}
	
	public void removeObserver(WeatherObserver obs) {
		if (!mObserverList.contains(obs)) return;
		System.out.println("removeObserver WeatherObserver : " + obs.toString());
		mObserverList.remove(obs);
	}
	
	public void setTemperature(float temp) {
		System.out.println("setTemperature temperature = " + temp);
		mTemperature = temp;
		for (WeatherObserver obs : mObserverList) obs.updateTemperature(temp);
	}
	
	public void setPressure(float pressure) {
		System.out.println("setPressure pressure = " + pressure);
		mPressure = pressure;
		for (WeatherObserver obs : mObserverList) obs.updatePressure(pressure);
	}
	
	public void clearObserver() {
		mObserverList.clear();
	}
}
