import cv2

file_path = '/media/frank/Data/Coding/Python/tga_Check/tga/grass.tga'
print(f"Trying to load: {file_path}")
img = cv2.imread(file_path, cv2.IMREAD_UNCHANGED)
if img is None:
    print(f"Failed to load {file_path}")
else:
    print(f"Width: {img.shape[1]}")
    print(f"Height: {img.shape[0]}")
    print(f"Channels: {img.shape[2] if len(img.shape) == 3 else 1}")
