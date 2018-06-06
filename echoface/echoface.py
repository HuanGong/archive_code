import face_recognition
from os import path
import os


class EchoFace:
    def __init__(self, samples_dir):
        self.storage = samples_dir
        self.faces_index_to_name = {}   # index : name
        self.known_encoding_faces = []  # faces data for recognition
        self.load_all_samples()

    def load_all_samples(self):

        indentifyIndex = 0

        files = os.listdir(self.storage)
        for file in files:
            if os.path.isdir(file): 
                continue
            face_image = face_recognition.load_image_file(path.join(self.storage, file))
            face_identifiers = face_recognition.face_encodings(face_image)
            if face_identifiers.count < 1:
               print('no face detected in this image', file) 
               continue
            self.faces_index_to_name[str(indentifyIndex)] = file
            self.known_encoding_faces.append(face_identifiers[0])
            indentifyIndex += 1

        print("all samples:", self.faces_index_to_name)

    def recognize(self, unknown_filename):

        recognized_names = []
          
        unknown_image = face_recognition.load_image_file(unknown_filename)
        unknown_encoding_images = face_recognition.face_encodings(unknown_image)
        if unknown_encoding_images.count < 1:
            print("can't find a face in this file:", unknown_filename)
            return recognized_names, "No Face Found" 
           
        #for index,item in enumerate(unknown_encoding_images):
        for item in unknown_encoding_images:
            face_recognition.face_distance
            results = face_recognition.compare_faces(self.known_encoding_faces, item, 0.4)
            for index, matched in enumerate(results):
                if matched:
                    face_name = self.faces_index_to_name[str(index)]
                    recognized_names.append(face_name)

        if recognized_names.count < 1:
            return recognized_names, "No Face Matched"
        return recognized_names, None

if __name__=="__main__":
    print("EchoFace Start.....")
    echoface = EchoFace("/home/gh/Desktop/samples")

    facedir = "/home/gh/Desktop/face"
    files = os.listdir(facedir)
    for file in files:
        if os.path.isdir(file):
           continue

        result, _ = echoface.recognize(path.join(facedir, file))
        print("recoginze:",file, " Get Result:", result)
