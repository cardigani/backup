   if(flags() & ImageConverterFlag::Verbose)
                Debug{} << "Trade::TgaImageConverter::convertToData(): converting from RGB to BGR";
            header.imageType = 2;
            break;
        case PixelFormat::RGBA8Unorm:
            if(flags() & ImageConverterFlag::Verbose)
                Debug{} << "Trade::TgaImageConverter::convertToData(): converting from RGBA to BGRA";
            header.imageType = 2;
            break;
        case PixelFormat::R8Unorm:
            header.imageType = 3;
            break;
        default:
            Error() << "Trade::TgaImageConverter::convertToData(): unsupported pixel format" << image.format();
            return {};
    }//yes

 const bool rleAcrossScanlines = configuration().value<bool>("rleAcrossScanlines");
        switch(image.format()) {
            case PixelFormat::R8Unorm:
                rleEncode<UnsignedByte>(data, image, rleAcrossScanlines);
                break;
            case PixelFormat::RGB8Unorm:
                rleEncode<Vector3ub>(data, image, rleAcrossScanlines);
                break;
            case PixelFormat::RGBA8Unorm:
                rleEncode<Vector4ub>(data, image, rleAcrossScanlines);
                break;
