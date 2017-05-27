class Test{
	public static void main(String[] args) {
		Double[] d = new Double[5];
		d[0] = 1.0D;
		d[1] = 1.0D;
		d[2] = 2.0D;
		d[3] = 2.0D;
		d[4] = 5.0D;
		UngroupedData a = new UngroupedData(d);
		a.setMode();
		System.out.println(a.modeType);
		a.displayMode();
	}
}