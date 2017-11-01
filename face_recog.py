#Requires OpenFace and dlib

'''To install openface, follow the below instructions:

git clone https://github.com/cmusatyalab/openface.git
cd openface
pip install -r requirements.txt
sudo python setup.py install
To download the trained model:

sh models/get-models.sh'''

import sys
import dlib
import cv2
import openface
from skimage import io

class recignitionLogic:

    def __init__(self, imageName):
        self.filename = imageName

        #Create HOG detector
        self.face_detector = dlib.get_frontal_face_detector()

        self.win = dlib.image_window()

        #load image to array
        self.image = io.imread(file_name)

    def findFaces(self):
        #return 0 if error. Else returns number of faces found
        try:
            self.detected_faces = face_detector(self.image, 1)
            return len(detected_faces)
        except:
            return 0

    def outlineFaces(self):
        self.win.set_image(image)

        for i, face_rect in enumerate(self.detected_faces):
            # Detected faces are returned as an object with the coordinates
        	# of the top, left, right and bottom edges
        	#print("- Face #{} found at Left: {} Top: {} Right: {} Bottom: {}".format(i, face_rect.left(), face_rect.top(), face_rect.right(), face_rect.bottom()))

            win.add_overlay(face_rect)
        #wait for user to continue
        dlib.hit_enter_to_continue()

    def determineLandmarks(self):
        # You can download the required pre-trained face detection model here:
        # http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2
        self.predictor_model = "shape_predictor_68_face_landmarks.dat"

        self.face_pose_predictor = dlib.shape_predictor(predictor_model)

        # Loop through each face we found in the image
        for i, face_rect in enumerate(self.detected_faces):

        	# Detected faces are returned as an object with the coordinates
        	# of the top, left, right and bottom edges
        	#print("- Face #{} found at Left: {} Top: {} Right: {} Bottom: {}".format(i, face_rect.left(), face_rect.top(), face_rect.right(), face_rect.bottom()))

        	# Draw a box around each face we found
        	win.add_overlay(face_rect)

        	# Get the the face's pose
        	self.pose_landmarks = face_pose_predictor(image, face_rect)

        	# Draw the face landmarks on the screen.
        	win.add_overlay(pose_landmarks)

        dlib.hit_enter_to_continue()

    def projectingFaces(self):
        self.face_aligner = openface.AlignDlib(self.predictor_model)

        image = cv2.imread(self.filename)

        # Loop through each face we found in the image
        for i, face_rect in enumerate(detected_faces):

        	# Detected faces are returned as an object with the coordinates
        	# of the top, left, right and bottom edges
        	#print("- Face #{} found at Left: {} Top: {} Right: {} Bottom: {}".format(i, face_rect.left(), face_rect.top(), face_rect.right(), face_rect.bottom()))

        	# Get the the face's pose
        	pose_landmarks = face_pose_predictor(image, face_rect)

        	# Use openface to calculate and perform the face alignment
        	alignedFace = face_aligner.align(534, image, face_rect, landmarkIndices=openface.AlignDlib.OUTER_EYES_AND_NOSE)

        	# Save the aligned image to a file
        	cv2.imwrite("aligned_face_{}.jpg".format(i), alignedFace)
