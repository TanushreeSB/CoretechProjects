import streamlit as st
import cv2 as cv
import numpy as np
import keras

# List of disease labels
label_name = ['Apple scab', 'Apple Black rot', 'Apple Cedar apple rust', 'Apple healthy', 'Cherry Powdery mildew',
'Cherry healthy', 'Corn Cercospora leaf spot Gray leaf spot', 'Corn Common rust', 'Corn Northern Leaf Blight', 'Corn healthy', 
'Grape Black rot', 'Grape Esca', 'Grape Leaf blight', 'Grape healthy', 'Peach Bacterial spot', 'Peach healthy', 'Pepper bell Bacterial spot', 
'Pepper bell healthy', 'Potato Early blight', 'Potato Late blight', 'Potato healthy', 'Strawberry Leaf scorch', 'Strawberry healthy',
'Tomato Bacterial spot', 'Tomato Early blight', 'Tomato Late blight', 'Tomato Leaf Mold', 'Tomato Septoria leaf spot',
'Tomato Spider mites', 'Tomato Target Spot', 'Tomato Yellow Leaf Curl Virus', 'Tomato mosaic virus', 'Tomato healthy']

# Prevention tips for each disease
disease_prevention_tips = {
    'Apple scab': "Preventive measures include applying fungicides, removing fallen leaves, and selecting resistant varieties of apples.",
    'Apple Black rot': "Prune infected trees, remove infected fruit and debris, and apply appropriate fungicides.",
    'Apple Cedar apple rust': "Remove infected leaves, apply fungicides, and ensure proper air circulation around the trees.",
    'Cherry Powdery mildew': "Ensure good spacing between trees, prune infected leaves, and apply fungicides.",
    'Corn Cercospora leaf spot Gray leaf spot': "Avoid overhead irrigation, plant resistant varieties, and apply fungicides.",
    'Corn Common rust': "Plant resistant corn varieties and apply fungicides if necessary.",
    'Corn Northern Leaf Blight': "Ensure proper spacing for air circulation, avoid planting corn in areas with high humidity, and use resistant varieties.",
    'Grape Black rot': "Prune infected vines, remove debris, and apply fungicides at the right growth stages.",
    'Grape Esca': "Remove and destroy infected vines, and ensure good vineyard management practices.",
    'Grape Leaf blight': "Maintain proper vine spacing, prune infected leaves, and apply fungicides.",
    'Peach Bacterial spot': "Prune infected branches, remove fallen leaves, and apply bactericides during the growing season.",
    'Pepper bell Bacterial spot': "Use disease-free seeds, avoid overhead irrigation, and apply bactericides.",
    'Potato Early blight': "Rotate crops, remove infected plant debris, and apply fungicides as needed.",
    'Potato Late blight': "Use disease-resistant varieties, avoid wet conditions, and apply fungicides.",
    'Strawberry Leaf scorch': "Ensure proper drainage, avoid overcrowding, and remove infected leaves.",
    'Tomato Bacterial spot': "Remove infected leaves, practice crop rotation, and apply bactericides.",
    'Tomato Early blight': "Rotate crops, remove infected debris, and apply fungicides.",
    'Tomato Late blight': "Avoid overhead watering, remove infected plants, and apply fungicides.",
    'Tomato Leaf Mold': "Improve air circulation around plants, remove infected leaves, and apply fungicides.",
    'Tomato Septoria leaf spot': "Remove infected leaves, rotate crops, and apply fungicides.",
    'Tomato Spider mites': "Use appropriate miticides, prune infected areas, and maintain proper irrigation.",
    'Tomato Target Spot': "Remove infected leaves, rotate crops, and apply fungicides.",
    'Tomato Yellow Leaf Curl Virus': "Control the vector (whiteflies) through insecticides and proper plant management.",
    'Tomato mosaic virus': "Remove infected plants, control aphids, and avoid handling plants when wet.",
}

st.write("""
The leaf disease detection model is built using deep learning techniques, and it uses transfer learning to leverage the pre-trained knowledge of a base model. The model is trained on a dataset containing images of 33 different types of leaf diseases. For more information about the architecture, dataset, and training process, please refer to the code and documentation provided.
""")              

st.write("Please input only leaf images of Apple, Cherry, Corn, Grape, Peach, Pepper, Potato, Strawberry, and Tomato. Otherwise, the model may not work properly.")

# Load the pre-trained model
model = keras.models.load_model('Training/model/Leaf Deases(96,88).h5')

# Upload image
uploaded_file = st.file_uploader("Upload an image")
if uploaded_file is not None:
    image_bytes = uploaded_file.read()
    img = cv.imdecode(np.frombuffer(image_bytes, dtype=np.uint8), cv.IMREAD_COLOR)
    normalized_image = np.expand_dims(cv.resize(cv.cvtColor(img, cv.COLOR_BGR2RGB), (150, 150)), axis=0)
    predictions = model.predict(normalized_image)
    
    # Show the uploaded image
    st.image(image_bytes)
    
    # Get the predicted disease
    predicted_label = label_name[np.argmax(predictions)]
    prediction_confidence = predictions[0][np.argmax(predictions)] * 100
    
    if prediction_confidence >= 80:
        st.write(f"Result is: {predicted_label} (Confidence: {prediction_confidence:.2f}%)")
        
        # Provide prevention tips based on the detected disease
        if predicted_label in disease_prevention_tips:
            st.write("Prevention Tips:")
            st.write(disease_prevention_tips[predicted_label])
        else:
            st.write("No prevention tips available for this disease.")
    else:
        st.write("Confidence too low. Try another image.")
