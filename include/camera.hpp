/** 
 * @file camera.hpp
 * @brief Camera abstract class. 
 */

#ifndef DEF_CAMERA_HPP
#define DEF_CAMERA_HPP

/**
 * @brief Abstract camera class. 
 * @details The @p Camera class represents the camera interface for the CWIS experiment. 
 *          Its only purpose is to propose a simple way to extend the camera acquisition
 *          software to different camera models. 
 */
class Camera {

    public: 
        virtual void acquire(void) = 0;
        virtual void capture(int *image) = 0; 
        virtual void setFrameRate(double frameRate) = 0;
        virtual void setImageSize(int width, int height, int x, int y) = 0; 
        virtual ~Camera() {};

    private:
        /** @brief Current camera framerate (in frames per second). */
        double m_frameRate;
        /** @brief Max image width, defined by the camera sensor. */
        int maxWidth; 
        /** @brief Max image height, defined by the camera sensor. */
        int maxHeight; 
};


#endif  /* DEF_CAMERA_HPP */

