//
//  Texture.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include "Texture.h"

namespace Texture {

GLubyte image1[256][256][3];
GLubyte image2[512][256][3];
GLubyte image3[256][256][3];
GLubyte image4[64][64][3];


void
init_texture()
    {
        read_texture("grass11.ppm", 0);
        read_texture("basketball.ppm", 1);
        read_texture("brick1.ppm", 2);
        for ( int i = 0; i < 64; i++ ) {
            for ( int j = 0; j < 64; j++ ) {
                GLubyte c = (((i & 0x8) == 0) ^ ((j & 0x8)  == 0)) * 255;
                image4[i][j][0]  = c;
                image4[i][j][1]  = c;
                image4[i][j][2]  = c;
            }
        }
        
        // Initialize texture objects
        glGenTextures( 10, Decleration::textures );

        glBindTexture( GL_TEXTURE_2D, Decleration::textures[0] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image1 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[1] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 512, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image2 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[2] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 512, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image2 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[3] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 512, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image2 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[4] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image3 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[5] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image3 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[6] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image3 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[7] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, image3 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[8] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, image4 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[9] );
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, image4 );
        glGenerateMipmap(GL_TEXTURE_2D); // try also activating mipmaps for the second texture object
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
        
}

void read_texture(string filename, int imageIndex)
{
    int k, n, m;
    int red, green, blue;
    ifstream myfile (filename);
    if (!myfile.is_open()) {
        std::cerr << "Could not open the file - '"
        << filename << "'" << endl;
    }
    string line;
    myfile >> line;
    if(line[0]!='P'|| line[1] != '3'){
        std::cerr << filename << " is not a PPM file!\n" << endl;
        exit(0);
    }
    std::cout << filename << " is a PPM file!\n" << endl;
    myfile >> line;
    while(line[0] == '#')
    {
        myfile >> line;
        std::cout << line << endl;
    }
    n = stoi( line );
    myfile >> m;
    myfile >> k;
    
    std::cout << n << " rows " << m << " columns, max value:  " << k << endl;

    int i,j;
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            myfile >> red >> green >> blue;

            if (imageIndex == 0)
            {
                image1[i][j][0]=red;
                image1[i][j][1]=green;
                image1[i][j][2]=blue;
            }else if (imageIndex == 1){
                image2[i][j][0]=red;
                image2[i][j][1]=green;
                image2[i][j][2]=blue;
            }else{
                image3[i][j][0]=red;
                image3[i][j][1]=green;
                image3[i][j][2]=blue;
            }
        
        }
    }
}

}
