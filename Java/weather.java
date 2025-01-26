import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import org.json.JSONObject;

public class PlaceWeatherApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Place Weather App");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 300);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        frame.add(panel);

        JLabel locationLabel = new JLabel("Enter Location: ");
        JTextField locationField = new JTextField(20);
        JButton getWeatherButton = new JButton("Get Weather");
        JTextArea weatherTextArea = new JTextArea(10, 30);
        weatherTextArea.setEditable(false);
        weatherTextArea.setLineWrap(true);
        weatherTextArea.setWrapStyleWord(true);
        weatherTextArea.setFont(new Font("Arial", Font.PLAIN, 14));

        // Adding components with GridBagLayout
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.insets = new Insets(10, 10, 10, 10);  // Add padding
        panel.add(locationLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        panel.add(locationField, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(getWeatherButton, gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.gridwidth = 2;  // Span across 2 columns
        panel.add(new JScrollPane(weatherTextArea), gbc);

        getWeatherButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String location = locationField.getText().trim();
                if (!location.isEmpty()) {
                    String apiKey = "a301a9da9dec12f7b394e5599cf244ff";
                    String apiUrl = "http://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + apiKey;

                    // Displaying loading message
                    weatherTextArea.setText("Loading...");

                    try {
                        URL url = new URL(apiUrl);
                        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                        Scanner scanner = new Scanner(connection.getInputStream());

                        StringBuilder response = new StringBuilder();
                        while (scanner.hasNextLine()) {
                            response.append(scanner.nextLine());
                        }

                        // Parsing JSON response and displaying data
                        JSONObject jsonResponse = new JSONObject(response.toString());
                        String weatherDescription = jsonResponse.getJSONArray("weather").getJSONObject(0).getString("description");
                        double temperatureKelvin = jsonResponse.getJSONObject("main").getDouble("temp");
                        double temperatureCelsius = temperatureKelvin - 273.15;
                        String locationName = jsonResponse.getString("name");

                        String formattedWeather = String.format(
                            "Weather in %s:\nDescription: %s\nTemperature: %.2f°C",
                            locationName, weatherDescription, temperatureCelsius
                        );

                        weatherTextArea.setText(formattedWeather);

                        scanner.close();
                        connection.disconnect();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                        weatherTextArea.setText("Error fetching data. Please try again.");
                    }
                } else {
                    weatherTextArea.setText("Please enter a location.");
                }
            }
        });

        frame.setVisible(true);
    }
}
