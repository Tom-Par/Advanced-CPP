
template <typename T, int dim, T side> 
class hypercube {
public:
    constexpr T get_volume() {
        if (dim < 0)
                return -1;
            T volume = 0;
            for (int i = 0; i < dim; ++i)
                volume = (i == 0) ? side : volume * side;
            return volume;
        }
    };

